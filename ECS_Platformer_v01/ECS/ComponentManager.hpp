//
//  ComponentManager.hpp
//  ECS_Test
//
//  Created by Lucas Giglio on 25.12.20.
//
//  This class manages all component-related functions
//
//

#ifndef ComponentManager_hpp
#define ComponentManager_hpp

#include "Types.hpp"
#include <map>
#include "GenericArray.hpp"
#include "System.h"


class ComponentManager {
public:
    template<typename T>
    void CreateComponentType() {
        const char* typeName = typeid(T).name();
        if (mComponentTypes.find(typeName) == mComponentTypes.end()) {
            mComponentTypes.insert({typeName, mNextComponentType}); // Insert new component type into the map
            
            mComponentArray.insert({typeName, std::make_shared<GenericArray<T>>()}); // Create a GenericArray pointer with std::make_shared<GenericArray<T>>() and add it to the map
            mNextComponentType++;
        }        
    }
    
    template<typename T>
    void DeleteComponentType() {
        const char* typeName = typeid(T).name();
        if (mComponentTypes.find(typeName) != mComponentTypes.end()) { // Check if component is already created
            mComponentTypes.erase(typeName);
        }
    }
    
    template<typename T>
    ComponentType GetComponentType() {
        const char* typeName = typeid(T).name();
        assert (mComponentTypes.find(typeName) != mComponentTypes.end() && "Component not found") ;
        return mComponentTypes.at(typeName);
    }
    
    // Entity to Component object specific methods
    template<typename T>
    void AddComponentToEntity(Entity entity, T component) {
        GetGenericArray<T>()->AddComponentoToEntity(entity, component);
    }
    
    template<typename T>
    T& GetComponentFromEntity(Entity entity) { // Return adress of the component from the mComponentMap of the class GenericArray
        return GetGenericArray<T>()->GetComponentFromEntity(entity);
    }
    
    // System to Component object specific methods
    template<typename T>
    void AddComponentToSystem(std::shared_ptr<System> system, T component) {
        GetGenericArray<T>()->AddComponentToSystem(system, component);
    }
    
    template<typename T>
    T& GetComponentFromSystem(std::shared_ptr<System> system) { // Return adress of the component from the mComponentMap of the class GenericArray
        return GetGenericArray<T>()->GetComponentFromSystem(system);
    }
    
    
    
private:
    std::map<const char*, ComponentType> mComponentTypes {}; // Component type array
    
    std::map<const char*, std::shared_ptr<IGenericArray>> mComponentArray {}; // Component array
    
    ComponentType mNextComponentType {};
    
    template<typename T>
    std::shared_ptr<GenericArray<T>> GetGenericArray() {
        const char* typeName = typeid(T).name();
        return std::static_pointer_cast<GenericArray<T>>(mComponentArray[typeName]);
    }
};


#endif /* ComponentManager_; */
