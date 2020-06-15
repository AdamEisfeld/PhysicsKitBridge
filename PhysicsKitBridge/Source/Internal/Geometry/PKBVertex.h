//
//  PKBVertex.h
//  BulletPhysics
//
//  Created by Adam Eisfeld on 2020-06-12.
//  Copyright © 2020 adam. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

struct BLVector3;

@interface PKBVertex : NSObject

@property (nonatomic, readonly) struct BLVector3 position;

- (instancetype)initWithPosition: (struct BLVector3)position;

@end

NS_ASSUME_NONNULL_END
