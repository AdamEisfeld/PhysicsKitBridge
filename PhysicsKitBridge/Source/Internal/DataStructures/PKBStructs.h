//
//  BLStructs.h
//  BulletPhysics
//
//  Created by Adam Eisfeld on 2020-06-12.
//  Copyright © 2020 adam. All rights reserved.
//

struct BLVector3 {
    float x;
    float y;
    float z;
};

struct BLQuaternion {
    float x;
    float y;
    float z;
    float w;
};

struct BLMatrix4 {

    float m11;
    float m12;
    float m13;
    float m14;
    float m21;
    float m22;
    float m23;
    float m24;
    float m31;
    float m32;
    float m33;
    float m34;
    float m41;
    float m42;
    float m43;
    float m44;
    
};

#ifdef __cplusplus
extern "C" {
#endif

extern struct BLVector3 BLVector3Make(float x, float y, float z);

extern struct BLQuaternion BLQuaternionMake(float x, float y, float z, float w);
extern struct BLQuaternion BLQuaternionMakeIdentity();

extern struct BLMatrix4 BLMatrix4Make(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44);
extern struct BLMatrix4 BLMatrix4MakeIdentity();

#ifdef __cplusplus
}
#endif


