//
//  BLStructs.m
//  BulletPhysics
//
//  Created by Adam Eisfeld on 2020-06-12.
//  Copyright © 2020 adam. All rights reserved.
//

#import "PKBStructs.h"
#import "PKBStructs+Internal.h"

struct BLVector3
BLVector3Make(float x, float y, float z) {
    struct BLVector3 v; v.x = x; v.y = y; v.z = z; return v;
}

struct BLQuaternion
BLQuaternionMake(float x, float y, float z, float w) {
    struct BLQuaternion q; q.x = x; q.y = y; q.z = z; q.w = w; return q;
}

struct BLQuaternion
BLQuaternionMakeIdentity() {
    struct BLQuaternion q; q.x = 0; q.y = 0; q.z = 0; q.w = 1; return q;
}

struct BLMatrix4
BLMatrix4Make(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44) {
    struct BLMatrix4 m;
    m.m11 = m11;
    m.m12 = m12;
    m.m13 = m13;
    m.m14 = m14;
    
    m.m21 = m21;
    m.m22 = m22;
    m.m23 = m23;
    m.m24 = m24;
    
    m.m31 = m31;
    m.m32 = m32;
    m.m33 = m33;
    m.m34 = m34;
    
    m.m41 = m41;
    m.m42 = m42;
    m.m43 = m43;
    m.m44 = m44;
    
    return m;
}

struct BLMatrix4
BLMatrix4MakeIdentity() {
    struct BLMatrix4 m;
    m.m11 = 1; m.m12 = 0; m.m13 = 0; m.m14 = 0;
    m.m21 = 0; m.m22 = 1; m.m23 = 0; m.m24 = 0;
    m.m31 = 0; m.m32 = 0; m.m33 = 1; m.m34 = 0;
    m.m41 = 0; m.m42 = 0; m.m43 = 0; m.m44 = 1;
    return m;
}

struct BLMatrix4
BLMatrix4MakeFrom(btTransform c_transform) {
    btScalar c_transformComponents[16];
    c_transform.getOpenGLMatrix(c_transformComponents);
    
    return BLMatrix4Make(c_transformComponents[0],
                        c_transformComponents[1],
                        c_transformComponents[2],
                        c_transformComponents[3],
                        
                        c_transformComponents[4],
                        c_transformComponents[5],
                        c_transformComponents[6],
                        c_transformComponents[7],
                        
                        c_transformComponents[8],
                        c_transformComponents[9],
                        c_transformComponents[10],
                        c_transformComponents[11],
                        
                        c_transformComponents[12],
                        c_transformComponents[13],
                        c_transformComponents[14],
                        c_transformComponents[15]);
}

btTransform
btTransformMakeFrom(BLMatrix4 transform) {
    btScalar c_transformComponents[16];
    c_transformComponents[0] = transform.m11;
    c_transformComponents[1] = transform.m12;
    c_transformComponents[2] = transform.m13;
    c_transformComponents[3] = transform.m14;
    
    c_transformComponents[4] = transform.m21;
    c_transformComponents[5] = transform.m22;
    c_transformComponents[6] = transform.m23;
    c_transformComponents[7] = transform.m24;
    
    c_transformComponents[8] = transform.m31;
    c_transformComponents[9] = transform.m32;
    c_transformComponents[10] = transform.m33;
    c_transformComponents[11] = transform.m34;
    
    c_transformComponents[12] = transform.m41;
    c_transformComponents[13] = transform.m42;
    c_transformComponents[14] = transform.m43;
    c_transformComponents[15] = transform.m44;
    
    btTransform c_transform;
    c_transform.setFromOpenGLMatrix(c_transformComponents);
    return c_transform;
}
