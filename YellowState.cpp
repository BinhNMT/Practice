#include <iostream>
#include <unistd.h>
#include "YellowState.h"

using namespace std;

YellowState::YellowState(TrafficControler* p_controler)
{
    m_controler = p_controler;
    m_controler->setLightState(2);
}

void YellowState::stateHandling(unsigned int timeCount)
{
    if (m_controler->getSignalDirector() == 0)
    {
        cout << "Yellow light now" << endl;

        if (timeCount > 0)
        {
            sleep(timeCount);
            m_controler->setState(m_controler->getRedState());
            m_controler->stateHandling(timeCount);
        }
    }
}