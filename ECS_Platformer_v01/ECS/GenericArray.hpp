//
//  GenericArray.hpp
//  ECS_Test
//
//  Created by Lucas Giglio on 27.12.20.
//
//  Generic class T to support the handling of different component types and systems together with an entity.
//
//

#ifndef GenericArray_hpp
#define GenericArray_hpp

#include <map>
#include "Types.hpp"
#include "System.h"


class IGenericArray {
public:
    virtual ~IGenericArray() {}
};

template <typename T>
class GenericArray : public IGenericArray {
public:
    
    void AddComponentoToEntity(Entity entity, T component) {
        mComponentMap.insert({mEntityComponentArrayIndex, component}); // insert component into vector using new index
        mEntityToComponentMap.insert({entity, mEntityComponentArrayIndex});
        mEntityComponentArrayIndex++;        
    }
    
    // Return reference of the component given an entity
    T& GetComponentFromEntity(Entity entity) {
        auto it = mEntityToComponentMap.find(entity);
        if (it != mEntityToComponentMap.end()) {
            return mComponentMap[it->second];
        } else {
            mComponentMap[it->second].nullComponent = true; // return a nullable component
            return mComponentMap[it->second];
        }
            
    }
    
    
    void AddComponentToSystem(std::shared_ptr<System> system, T component) {
        for (auto it = mComponentMap.begin(); it != mComponentMap.end(); it++) {
            if (it->second == component) { // Insert only if a component is already available
                mSystemToComponentMap.insert({system, it->first}); // map system to the index of the component vector
            }
        }
    }
    
    
    // Return reference of the component given a system
    T& GetComponentFromSystem(std::shared_ptr<System> system) {
        assert(mSystemToComponentMap.find(system) != mSystemToComponentMap.end() && "System not assigned to component");
        return mComponentMap[mSystemToComponentMap[system]];
    }
    
    
    
    
private:    
    std::map<Entity, size_t> mEntityToComponentMap; // Entity to component Map - size_t = size_t of mComponentMap
    std::map<size_t, T> mComponentMap; // Component Map to retrieve component objects - size_t = size_t of mEntityToComponentMap
    
    std::map<std::shared_ptr<System>, size_t> mSystemToComponentMap; // System to component Map - size_t = size_t of mSystemMap
    std::map<size_t, T> mSystemMap; // System Map to retrieve component objects - size_t = size_t of mSystemToComponentMap
    
    std::size_t mEntityComponentArrayIndex; // Index for Entity X Component maps
    std::size_t mSystemComponentArrayIndex; // Index for System X Component system
};



#endif /* GenericArray_hpp */
