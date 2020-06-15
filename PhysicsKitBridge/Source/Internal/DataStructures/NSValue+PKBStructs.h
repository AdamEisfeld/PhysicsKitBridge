//
//  NSValue+BLStructs.h
//  BulletPhysics
//
//  Created by Adam Eisfeld on 2020-06-12.
//  Copyright © 2020 adam. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

struct BLVector3;

@interface NSValue (BLAdditions)

+ (NSValue *)valueWithBLVector3:(struct BLVector3)v;

@property(nonatomic, readonly) struct BLVector3 BLVector3Value;


@end

NS_ASSUME_NONNULL_END
