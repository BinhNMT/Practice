#include "IState.h"
#include "TrafficControler.h"

class ResumeState: public IState
{
private:
    TrafficControler* m_controler;

public:
    ResumeState(TrafficControler* p_controler);
    void stateHandling(unsigned int timeCount);
};