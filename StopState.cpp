#include <iostream>
#include <unistd.h>
#include "StopState.h"

using namespace std;

StopState::StopState(TrafficControler* p_controler)
{
    m_controler = p_controler;
}

void StopState::stateHandling(unsigned int timeCount)
{
    cout << "Light are stop working now" << endl;
    m_controler->setSignalDirector(1);
}