#include <iostream>
#include <unistd.h>
#include <fstream>
#include <sstream>

using namespace std;

/*=============================================================*/
class IState
{
public:
    virtual void stateHandling(unsigned int timeCount) = 0;
};


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


/*=============================================================*/
class GreenState: public IState
{
private:
    TrafficControler* m_controler;

public:
    GreenState(TrafficControler* p_controler);
    void stateHandling(unsigned int timeCount);
};

GreenState::GreenState(TrafficControler* p_controler)
{
    m_controler = p_controler;
    m_controler->setLightState(1);
}


void GreenState::stateHandling(unsigned int timeCount)
{
    if (m_controler->getSignalDirector() == 0)
    {
        cout << "Green light now" << endl;

        if (timeCount > 0)
        {
            sleep(timeCount);
            m_controler->setState(m_controler->getYellowState());
            m_controler->stateHandling(timeCount);
        }
    }
}


/*=============================================================*/
class YellowState: public IState
{
private:
    TrafficControler* m_controler;

public:
    YellowState(TrafficControler* p_controler);
    void stateHandling(unsigned int timeCount);
};

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


/*=============================================================*/
class RedState: public IState
{
private:
    TrafficControler* m_controler;

public:
    RedState(TrafficControler* p_controler);
    void stateHandling(unsigned int timeCount);
};

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


/*=============================================================*/
class StopState: public IState
{
private:
    TrafficControler* m_controler;

public:
    StopState(TrafficControler* p_controler);
    void stateHandling(unsigned int timeCount);
};

StopState::StopState(TrafficControler* p_controler)
{
    m_controler = p_controler;
}

void StopState::stateHandling(unsigned int timeCount)
{
    cout << "Light are stop working now" << endl;
    m_controler->setSignalDirector(1);
}


/*=============================================================*/
class ResumeState: public IState
{
private:
    TrafficControler* m_controler;

public:
    ResumeState(TrafficControler* p_controler);
    void stateHandling(unsigned int timeCount);
};

ResumeState::ResumeState(TrafficControler* p_controler)
{
    m_controler = p_controler;
}

void ResumeState::stateHandling(unsigned int timeCount)
{
    cout << "Light are resume to working now" << endl;
}


/*=============================================================*/
class RestartState: public IState
{
private:
    TrafficControler* m_controler;

public:
    RestartState(TrafficControler* p_controler);
    void stateHandling(unsigned int timeCount);
};

RestartState::RestartState(TrafficControler* p_controler)
{
    m_controler = p_controler;
}

void RestartState::stateHandling(unsigned int timeCount)
{
    cout << "Light are Restart now" << endl;
    m_controler->setSignalDirector(0);
    m_controler->setState(m_controler->getGreenState());
    m_controler->stateHandling(timeCount);
}


/*=============================================================*/
TrafficControler::TrafficControler()
{
    m_greenState = new GreenState(this);
    m_yellowState = new YellowState(this);
    m_redState = new RedState(this);
    m_stopState = new StopState(this);
    m_resumeState = new ResumeState(this);
    m_restartState = new RestartState(this);
    m_currentState = m_greenState;
    signalDirector = 0;
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

void TrafficControler::setSignalDirector(int p_signal)
{
    signalDirector = p_signal;
}

void TrafficControler::setLightState(int p_stateCode)
{
    lightState = p_stateCode;
}

int TrafficControler::getLightState()
{
    return lightState;
}


/*=============================================================*/
class ConfigScanner
{
private:
    std::string fileName;

public:
    ConfigScanner(std::string p_inputFileName);
    int readConfig();
};

ConfigScanner::ConfigScanner(std::string p_inputFileName)
{
    fileName = p_inputFileName;
}

int ConfigScanner::readConfig()
{
    int ret;
    string data;
    ifstream infile; 
    infile.open(fileName); 
    infile >> data;
    stringstream geek(data);
    geek >> ret;
    return ret;
}

/*=============================================================*/
int main()
{
    // TrafficControler instance;
    // // instance.stateHandling(1);
    // instance.setState(instance.getStopState());
    // instance.stateHandling(1);
    
    // instance.setState(instance.getGreenState());
    // instance.stateHandling(1);
    
    // instance.setState(instance.getRestartState());
    // instance.stateHandling(1);
    return 0;
}