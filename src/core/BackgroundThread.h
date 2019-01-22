#ifndef BACKGROUND_THREAD_H
#define BACKGROUND_THREAD_H

#include <thread>
#include <atomic>
#include <iostream>
#include <utility>
#include "../object/Birdy.h"
#include "../scene/SceneBuilder.h"

namespace birdy
{

    // have the below function run on a background thread
    // as the main thread renders a transition segment between scenes
    // wormEaten is the control point that activates the reset of a scene when its set to false
    void birdyTransition(std::atomic_bool* backgroundThreadCreated, Birdy* bird, SceneBuilder* sceneBuilder)
    {
        backgroundThreadCreated->store(true);
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        sceneBuilder->resetScene();
        bird->wormEaten = false;
        backgroundThreadCreated->store(false);
        std::cout << "Thread " << std::this_thread::get_id() << " has terminated" << std::endl;
    }

    class BackgroundThread 
    {
        public:
            BackgroundThread() : backgroundThreadCreated(false){}
            ~BackgroundThread()
            {
                if(m_thread != nullptr)
                {
                    m_thread->join();
                    delete m_thread;
                }
            }

            template<class Function, class... Args>
            void start(Function function, Args... args)
            {
                m_thread = new std::thread(function, &backgroundThreadCreated, args...);
            }

            std::thread::id getId()
            {
                return m_thread->get_id();
            }

            std::atomic_bool backgroundThreadCreated;

        private:
            std::thread* m_thread = nullptr;
    };
}

#endif