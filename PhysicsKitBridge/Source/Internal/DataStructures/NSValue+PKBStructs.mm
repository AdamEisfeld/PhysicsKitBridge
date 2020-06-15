//
//  NSValue+BLStructs.m
//  BulletPhysics
//
//  Created by Adam Eisfeld on 2020-06-12.
//  Copyright © 2020 adam. All rights reserved.
//

#import "NSValue+PKBStructs.h"
#import "PKBStructs.h"

@implementation NSValue (BLAdditions)

+ (NSValue *)valueWithBLVector3:(struct BLVector3)v {
    return [self valueWithBytes:&v objCType:@encode(struct BLVector3)];
}

- (struct BLVector3)BLVector3Value {
    struct BLVector3 value;
    [self getValue:&value];
    return value;
}

@end

