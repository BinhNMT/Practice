#include <iostream>
#include <unistd.h>
#include "RedState.h"

using namespace std;

RedState::RedState(TrafficControler* p_controler)
{
    m_controler = p_controler;
    m_controler->setLightState(3);
}

void RedState::stateHandling(unsigned int timeCount)
{
    if (m_controler->getSignalDirector() == 0)
    {
        cout << "Red light now" << endl;

        if (timeCount > 0)
        {
            sleep(timeCount);
            m_controler->setState(m_controler->getGreenState());
            m_controler->stateHandling(timeCount);
        }
    }
}