//
//  GONDevices.h
//
//  Created by Nicolas Goutaland on 03/04/15.
//  Copyright 2015 Nicolas Goutaland. All rights reserved.
//

// Screen type
#define IS_RETINA_SCREEN()                          (MAIN_SCREEN.scale > 1.0)

// Interface idiom
#define IS_IPHONE()         (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define IS_IPAD()           (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define IS_IPHONE_5()       ((UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone) && [UIScreen mainScreen].bounds.size.height == 568)
#define IS_IPHONE_6()       ((UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone) && [UIScreen mainScreen].bounds.size.height == 667)
#define IS_IPHONE_6Plus()   ((UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone) && [UIScreen mainScreen].scale == 3.0)

// Device informations
#define DEVICE_MODEL                                [CURRENT_DEVICE model]
#define DEVICE_LOCALIZED_MODEL                      [CURRENT_DEVICE localizedModel]
#define DEVICE_PLATFORM                             [CURRENT_DEVICE platform]
#define DEVICE_SYSTEM_NAME                          [CURRENT_DEVICE systemName]
#define DEVICE_SYSTEM_VERSION                       [CURRENT_DEVICE systemVersion]

// System version
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)              ([[CURRENT_DEVICE systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_IS_IOS4_OR_GREATER()                     SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"4.0")
#define SYSTEM_VERSION_IS_IOS5_OR_GREATER()                     SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"5.0")
#define SYSTEM_VERSION_IS_IOS6_OR_GREATER()                     SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"6.0")
#define SYSTEM_VERSION_IS_IOS7_OR_GREATER()                     SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"7.0")
#define SYSTEM_VERSION_IS_IOS8_OR_GREATER()                     SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"8.0")
#define SYSTEM_VERSION_IS_IOS9_OR_GREATER()                     SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"9.0")
