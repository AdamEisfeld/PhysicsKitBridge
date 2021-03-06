//
//  PKBCollisionShape.h
//  BulletPhysics
//
//  Created by Adam Eisfeld on 2020-06-12.
//  Copyright © 2020 adam. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PKBGeometry;
@class PKBCollisionShape;
@class PKBGeometry;

struct BLMatrix4;

@interface PKBCollisionShape : NSObject

@property (nonatomic, assign) struct BLMatrix4 transform;

- (instancetype)init;
- (instancetype)initWithSerializedData: (NSData *)serializedData;
- (instancetype)initSphereWithRadius: (float)radius transform: (struct BLMatrix4)transform;
- (instancetype)initBoxWithWidth: (float)width height: (float)height length: (float)length transform: (struct BLMatrix4)transform;
- (instancetype)initCapsuleWithRadius: (float)radius height: (float)height transform: (struct BLMatrix4)transform;
- (instancetype)initStaticPlaneWithDirection:(struct BLVector3)direction transform:(struct BLMatrix4)transform;
- (instancetype)initWithCollisionShape: (PKBCollisionShape *)collisionShape transform: (struct BLMatrix4)transform;
- (instancetype)initWithCollisionShapes: (NSArray <PKBCollisionShape *>*)collisionShapes transform: (struct BLMatrix4)transform;
- (instancetype)initConvexHullWithGeometry: (PKBGeometry *)geometry;
- (instancetype)initTriangleMeshWithGeometry: (PKBGeometry *)geometry;

- (NSData *)serialize;

@end

NS_ASSUME_NONNULL_END
