#include "IState.h"

class TrafficControler
{
private:
    IState* m_currentState;
    IState* m_greenState;
    IState* m_yellowState;
    IState* m_redState;
    IState* m_stopState;
    IState* m_resumeState;
    IState* m_restartState;
    int signalDirector;
    int lightState;

public:
    TrafficControler(/* args */);
    ~TrafficControler();
    void setState(IState* p_state);
    IState* getState();
    IState* getGreenState();
    IState* getYellowState();
    IState* getRedState();
    IState* getStopState();
    IState* getResumeState();
    IState* getRestartState();
    void stateHandling(unsigned int timeCount);
    int getSignalDirector();
    void setSignalDirector(int p_signal);
    void setLightState(int p_stateCode);
    int getLightState();
};