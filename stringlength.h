#ifndef STRINGLENGTH_H
#define STRINGLENGTH_H

#include "itask.h"

class StringLength : public ITask
{
public:
    virtual std::string Run(std::vector<std::string> _data) override;
};

#endif // STRINGLENGTH_H
