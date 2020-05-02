#ifndef TICKETS_H
#define TICKETS_H

#include "itask.h"

class Tickets : public ITask
{
public:
    virtual std::string Run(std::vector<std::string> _data) override;
};


#endif // TICKETS_H
