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
    void birdyTransitionTimer(std::atomic_bool* backgroundThreadCreated, 
        Birdy* bird, 
        SceneBuilder* sceneBuilder, 
        std::atomic_bool* threadDead)
    {
        backgroundThreadCreated->store(true);
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));

        if (threadDead)
            return;

        sceneBuilder->resetScene();
        bird->wormEaten = false;
        backgroundThreadCreated->store(false);
        std::cout << "Thread " << std::this_thread::get_id() << " has terminated" << std::endl;
    }

    class BackgroundThread 
    {
        public:
            BackgroundThread() : backgroundThreadCreated(false), threadDead(false){}
            ~BackgroundThread()
            {
                if(m_thread != nullptr)
                {
                    if (threadDead)
                    {
                        delete m_thread;
                        return;
                    }
                        
                    m_thread->join();
                    delete m_thread;
                }
            }

            inline std::thread* GetThread() const { return m_thread; }

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
            std::atomic_bool threadDead;

        private:
            std::thread* m_thread = nullptr;
    };
}

#endif