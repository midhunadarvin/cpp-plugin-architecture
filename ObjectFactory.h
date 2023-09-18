#ifndef OBJECT_FACTORY_DOT_H
#define OBJECT_FACTORY_DOT_H

#include "util/XMLHelper.h"
#include <unordered_map>
#include <typeinfo> // Include the header for typeid
#include <memory> // Include the header for std::make_shared
#include "commands/BaseComputationCommand.h"
#include "commands/SeniorCitizenCommand.h"
#include "commands/OrdinaryCitizenCommand.h"

class ObjectFactory
{
private:
    std::unordered_map<std::string, std::string> plugins;
    std::unordered_map<std::string, std::shared_ptr<BaseComputationCommand>> commands;

public:
    ObjectFactory(std::string xmlfile)
    {
        plugins = XMLHelper::LoadConfig(xmlfile);
    }


    std::shared_ptr<BaseComputationCommand> Get(std::string archetype, std::string mode = "singleton");
};


#endif