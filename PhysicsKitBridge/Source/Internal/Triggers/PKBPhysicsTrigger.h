//
//  PKBPhysicsTrigger.h
//  BulletPhysics
//
//  Created by Adam Eisfeld on 2020-06-12.
//  Copyright © 2020 adam. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

struct BLVector3;
struct BLQuaternion;

@class PKBRigidBody;
@class PKBCollisionShape;

@interface PKBPhysicsTrigger : NSObject

@property (nonatomic, assign) struct BLVector3 position;
@property (nonatomic, assign) struct BLQuaternion orientation;

- (instancetype)initWithCollisionShape: (PKBCollisionShape *)collisionShape;

- (NSArray <PKBRigidBody *>*)internalGetCollidingRigidBodies;

@end

NS_ASSUME_NONNULL_END
