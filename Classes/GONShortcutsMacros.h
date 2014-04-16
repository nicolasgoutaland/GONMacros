//
//  GONShortcutsMacros.h
//
//  Created by Nicolas Goutaland on 04/03/14.
//  Copyright 2014 Nicolas Goutaland. All rights reserved.
//

#ifndef LOCALIZED_STRING
    #define LOCALIZED_STRING(string)		NSLocalizedString(string, nil)
#else
    #pragma message("LOCALIZED_STRING already declared")
#endif

#define NOTIFICATION_CENTER                         [NSNotificationCenter defaultCenter]
#define FILE_MANAGER                                [NSFileManager defaultManager]
#define MAIN_BUNDLE                                 [NSBundle mainBundle]
#define MAIN_THREAD                                 [NSThread mainThread]
#define MAIN_SCREEN                                 [UIScreen mainScreen]
#define USER_DEFAULTS                               [NSUserDefaults standardUserDefaults]
#define APPLICATION                                 [UIApplication sharedApplication]
#define CURRENT_DEVICE                              [UIDevice currentDevice]
#define MAIN_RUN_LOOP                               [NSRunLoop mainRunLoop]
#define GENERAL_PASTEBOARD                          [UIPasteboard generalPasteboard]
#define LANG                                        LOCALIZED_STRING(@"globals.lang")
#define LANG_DISPLAY                                LOCALIZED_STRING(@"globals.langDisplay")

#define DEVICE_MODEL                                [CURRENT_DEVICE model]
#define DEVICE_LOCALIZED_MODEL                      [CURRENT_DEVICE localizedModel]
#define DEVICE_PLATFORM                             [CURRENT_DEVICE platform]
#define DEVICE_SYSTEM_NAME                          [CURRENT_DEVICE systemName]
#define DEVICE_SYSTEM_VERSION                       [CURRENT_DEVICE systemVersion]

#define APPLICATION_NAME                            ([[[MAIN_BUNDLE executablePath] pathComponents] lastObject])
#define APPLICATION_VERSION                         [MAIN_BUNDLE objectForInfoDictionaryKey:@"CFBundleVersion"]

#define NETWORK_ACTIVITY                            [APPLICATION networkActivityIndicatorVisible]

#define CLEAR_COLOR                                 [UIColor clearColor]

#define IS_RETINA_SCREEN                            (MAIN_SCREEN.scale == 2.0)

// Interface idiom
#define IS_IPHONE() 								(UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define IS_IPAD()		 							(UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define IS_IPHONE_5()  								((UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone) && [UIScreen mainScreen].bounds.size.height == 568)

#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[CURRENT_DEVICE systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_IS_IOS4_OR_GREATER           SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"4.0")
#define SYSTEM_VERSION_IS_IOS5_OR_GREATER           SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"5.0")
#define SYSTEM_VERSION_IS_IOS6_OR_GREATER           SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"6.0")
#define SYSTEM_VERSION_IS_IOS7_OR_GREATER           SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"7.0")
