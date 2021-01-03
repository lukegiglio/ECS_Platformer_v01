//
//  2DVector.h
//  DonkeyKong_ECS2
//
//  Created by Lucas Giglio on 29.12.20.
//

#ifndef _DVector_h
#define _DVector_h

class Vector2D {
public:
    Vector2D()
        : x(0.0f), y(0.0f)
    {}
    
    Vector2D(float x, float y)
        : x(x), y(y)
    {}
    
    Vector2D operator + (Vector2D const& v) {
        return Vector2D (
                         x + v.x,
                         y + v.y);
    }
    
    Vector2D operator += (Vector2D const& v) {
        return Vector2D (
                         x += v.x,
                         y += v.y);
    }
    
    Vector2D operator -= (Vector2D const& v) {
        return Vector2D (
                         x -= v.x,
                         y -= v.y);
    }
    
    Vector2D operator- (Vector2D const& v) {
        return Vector2D (
                         x - v.x,
                         y - v.y);
    }
    
    Vector2D operator * (float f) {
        return Vector2D (
                         x * f,
                         y * f);
    }
  
    float x, y;
};

#endif /* _DVector_h */
