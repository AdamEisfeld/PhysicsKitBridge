//
//  PKBViewController.m
//  PhysicsKitBridge
//
//  Created by AdamEisfeld on 06/15/2020.
//  Copyright (c) 2020 AdamEisfeld. All rights reserved.
//

#import "PKBViewController.h"
#import "PKBRigidBody.h"
// MUST IMPORT AS BELOW, NOT <PhysicsKitBridge/...>, otherwise we get "include of non modular header..." errors


@interface PKBViewController ()

@end

@implementation PKBViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    PKBRigidBody *body;
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
