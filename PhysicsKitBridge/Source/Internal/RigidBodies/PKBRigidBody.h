//
//  PKBRigidBody.h
//  BulletPhysics
//
//  Created by Adam Eisfeld on 2020-06-10.
//  Copyright © 2020 adam. All rights reserved.
//

#import <Foundation/Foundation.h>

struct BLVector3;
struct BLQuaternion;

typedef enum {
    PKBRigidBodyTypeStatic,
    PKBRigidBodyTypeKinematic,
    PKBRigidBodyTypeDynamic
} PKBRigidBodyType;

typedef struct BLMatrix4 (^PKBMotionStateTransformGetBlock)(void);
typedef void (^PKBMotionStateTransformSetBlock)(struct BLMatrix4);

@class PKBCollisionShape;

@interface PKBRigidBody : NSObject

@property (nonatomic) _Nullable PKBMotionStateTransformGetBlock onGetVisualTransform;
@property (nonatomic) _Nullable PKBMotionStateTransformSetBlock onSetVisualTransform;

NS_ASSUME_NONNULL_BEGIN

@property (nonatomic, assign) struct BLVector3 position;
@property (nonatomic, assign) struct BLQuaternion orientation;
@property (nonatomic, assign) struct BLMatrix4 transform;

@property (nonatomic, assign) struct BLVector3 linearVelocity;
@property (nonatomic, assign) struct BLVector3 angularVelocity;

@property (nonatomic, assign) struct BLVector3 linearVelocityFactor;
@property (nonatomic, assign) struct BLVector3 angularVelocityFactor;

@property (nonatomic, assign) float friction;
@property (nonatomic, assign) float rollingFriction;
@property (nonatomic, assign) float spinningFriction;

@property (nonatomic, assign) float restitution;

@property (nonatomic, assign) float linearDamping;
@property (nonatomic, assign) float angularDamping;

@property (nonatomic, assign) struct BLVector3 centerOfMass;

@property (nonatomic, assign) float linearSleepingThreshold;
@property (nonatomic, assign) float angularSleepingThreshold;

@property (nonatomic, assign) BOOL isCollisionEnabled;
@property (nonatomic, assign) BOOL isSleepingEnabled;
@property (nonatomic, assign) BOOL isForcesEnabled;

@property (nonatomic, readonly) PKBRigidBodyType rigidBodyType;

- (instancetype)initWithCollisionShape: (PKBCollisionShape *)collisionShape rigidBodyType: (PKBRigidBodyType)rigidBodyType mass:(float)mass;

- (void)clearForces;
- (void)applyForce: (struct BLVector3)force impulse: (BOOL)impulse;
- (void)applyTorque: (struct BLVector3)torque impulse: (BOOL)impulse;

@end

NS_ASSUME_NONNULL_END
