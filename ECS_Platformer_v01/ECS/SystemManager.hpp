//
//  SystemManager.hpp
//  ECS_Test
//
//  Created by Lucas Giglio on 25.12.20.
//
//  This class provides basic system functions
//
//

#ifndef SystemManager_hpp
#define SystemManager_hpp

#include "Types.hpp"
#include <map>
#include "System.h"

class SystemManager {
public:
    template <typename T>
    std::shared_ptr<T> CreateSystem() {
        const char* systemName = typeid(T).name();
        assert (mSystems.find(systemName) == mSystems.end() && "System already exists");
        
        auto system = std::make_shared<T>();
        mSystems.insert({systemName, system});
        return system;
    }
    
    template <typename T>
    std::shared_ptr<T> GetSystem() {
        const char* systemName = typeid(T).name();
        return dynamic_pointer_cast<T>(mSystems[systemName]);
    }
    
    
    
    
private:
    std::map<const char*, std::shared_ptr<System>> mSystems;
    
};

#endif /* SystemManager_hpp */
