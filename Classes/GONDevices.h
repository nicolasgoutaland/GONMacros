//
//  GONDevices.h
//
//  Created by Nicolas Goutaland on 03/04/15.
//  Copyright 2015 Nicolas Goutaland. All rights reserved.
//

// Interface idiom
#define IS_IPHONE()         (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define IS_IPAD()           (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define IS_IPHONE_5()       ((UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone) && [UIScreen mainScreen].bounds.size.height == 568)
#define IS_IPHONE_6()       ((UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone) && [UIScreen mainScreen].bounds.size.height == 667)
#define IS_IPHONE_6Plus()   ((UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone) && [UIScreen mainScreen].scale == 3.0)
