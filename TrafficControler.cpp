#include <iostream>
#include "IState.h"
#include "GreenState.h"
#include "YellowState.h"
#include "RedState.h"
#include "StopState.h"
#include "RestartState.h"
#include "ResumeState.h"
#include "TrafficControler.h"

TrafficControler::TrafficControler()
{
    m_greenState = new GreenState(this);
    m_yellowState = new YellowState(this);
    m_redState = new RedState(this);
    m_stopState = new StopState(this);
    m_resumeState = new ResumeState(this);
    m_restartState = new RestartState(this);
    m_currentState = m_greenState;
}

TrafficControler::~TrafficControler()
{
    if (m_greenState != nullptr)
    {
        delete m_greenState;
        m_greenState = nullptr;
    }

    if (m_yellowState != nullptr)
    {
        delete m_yellowState;
        m_yellowState = nullptr;
    }
    
    if (m_redState != nullptr)
    {
        delete m_redState;
        m_redState = nullptr;
    }

    if (m_stopState != nullptr)
    {
        delete m_stopState;
        m_stopState = nullptr;
    }

    if (m_resumeState != nullptr)
    {
        delete m_resumeState;
        m_resumeState = nullptr;
    }

    if (m_restartState != nullptr)
    {
        delete m_restartState;
        m_restartState = nullptr;
    }
    
    m_currentState = nullptr;
}

void TrafficControler::setState(IState* p_state)
{
    m_currentState = p_state;
}

IState* TrafficControler::getState()
{
    return m_currentState;
}

IState* TrafficControler::getGreenState()
{
    return m_greenState;
}

IState* TrafficControler::getYellowState()
{
    return m_yellowState;
}

IState* TrafficControler::getRedState()
{
    return m_redState;
}

IState* TrafficControler::getStopState()
{
    return m_stopState;
}

IState* TrafficControler::getResumeState()
{
    return m_resumeState;
}

IState* TrafficControler::getRestartState()
{
    return m_restartState;
}

void TrafficControler::stateHandling(unsigned int timeCount)
{
    m_currentState->stateHandling(timeCount);
}

int TrafficControler::getSignalDirector()
{
    return signalDirector;
}