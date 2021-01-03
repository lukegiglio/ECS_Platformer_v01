//
//  EntityManager.hpp
//  ECS_Test
//
//  Created by Lucas Giglio on 24.12.20.
//
//  This class provides basic entity functions
//
//

#ifndef EntityManager_hpp
#define EntityManager_hpp

#include "Types.hpp"
#include <vector>
#include <map>

class EntityManager {
public:
    
    void Init() {
        
    }
    
    Entity CreateEntity() {
        Entity mEntity;
        mEntity = mNextEntity;
        mEntities.push_back(mEntity);
        mNextEntity++;
        return mEntity;
    }
    
    void DeleteEntity(Entity e) {
        std::vector<Entity>::iterator it = std::find(mEntities.begin(), mEntities.end(), e);
        if (it != mEntities.end()) {
            mEntities.erase(it);
        }
    }
    
    std::vector<Entity> GetEntities() {
        return mEntities;
    }
    
    
    
private:
    std::vector<Entity> mEntities;
    Entity mNextEntity;
};

#endif /* EntityManager_hpp */
