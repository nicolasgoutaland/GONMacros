/*
 *  GONUtilsMacros.h
 *
 *  Created by Nicolas Goutaland on 04/03/14.
 *  Copyright 2014 Nicolas Goutaland. All rights reserved.
 *
 */

/** Utils macros **/
// Open URL
#define OPEN_URL(url)                                           [APPLICATION openURL:(url)]
#define OPEN_STRING_URL(url)                                    [APPLICATION openURL:[NSURL URLWithString:([url stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding])]]
#define CALL_NUMBER(number)                                     [APPLICATION openURL:[NSURL URLWithString:[@"tel://" stringByAppendingString:[number stringByReplacingOccurrencesOfString:@" " withString:@""]]]]

// Files
#define PATH_DOCUMENTS                                          [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0]
#define PATH_LIBRARY                                            [NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES) objectAtIndex:0]
#define PATH_PRIVATE_STORAGE                                    [[PATH_LIBRARY stringByAppendingPathComponent:@"Caches"] stringByAppendingPathComponent:@"PrivateStorage"]
#define PATH_FOR_RESOURCE(file, ext)                            (file ? [MAIN_BUNDLE pathForResource:(file) ofType:ext] : nil)
#define PATH_FOR_RESOURCE_IN_DIRECTORY(file, ext, directory)    (file ? [MAIN_BUNDLE pathForResource:(file) ofType:ext inDirectory:directory] : nil)
#define TEMPORARY_FILE_PATH                                     [NSTemporaryDirectory() stringByAppendingPathComponent:[NSString stringWithFormat:@"%f", [NSDate timeIntervalSinceReferenceDate]]]
#define REMOVE_ITEM_AT_PATH(path)                               [FILE_MANAGER removeItemAtPath:path error:nil]
#define FILE_EXISTS_AT_PATH(path)                               [FILE_MANAGER fileExistsAtPath:path]

// Network
#define NETWORK_ACTIVITY_ON                                     [APP_DELEGATE enableNetworkIndicator]
#define NETWORK_ACTIVITY_OFF                                    [APP_DELEGATE disableNetworkIndicator]

// Load a nib
#define LOAD_NIB_NAMED(nibName)                                 do{[MAIN_BUNDLE loadNibNamed:nibName owner:self options:nil];}while(0)

// User interactions
#define ENABLE_USER_INTERACTIONS                                [[APPLICATION delegate] endIgnoringInteractionEvents]
#define DISABLE_USER_INTERACTIONS                               [[APPLICATION delegate] beginIgnoringInteractionEvents]

// Notifications
#define NOTIFICATION_CENTER_REMOVE                              [NOTIFICATION_CENTER removeObserver:self]

// Allow conversion from nil to [NSNull null]
#define nilToNSNull(value)                                      (value ? value : [NSNull null])
#define NSNullToNil(value)                                      ((id)value == [NSNull null] ? nil : value)

// Device language override
#define APPLICATION_LANGUAGES_KEY                               @"AppleLanguages"
#define OVERRIDE_APPLICATION_LANGUAGE(newLang)                  do {[USER_DEFAULTS setObject:[NSArray arrayWithObject:newLang] forKey:APPLICATION_LANGUAGES_KEY]; [USER_DEFAULTS synchronize];} while(0)
#define RESET_APPLICATION_LANGUAGE                              do {[USER_DEFAULTS removeObjectForKey:APPLICATION_LANGUAGES_KEY]; [USER_DEFAULTS synchronize];} while(0)

// List all fonts available
#define DUMP_FONT_LIST()  do {\
    NSArray *familyNames = [[UIFont familyNames] sortedArrayUsingDescriptors:@[[NSSortDescriptor sortDescriptorWithKey:@"description" ascending:YES selector:@selector(localizedCaseInsensitiveCompare:)]]];\
    NSArray *fonts;\
    NSLog(@"Listing all availables fonts : ");\
    NSLog(@"-------------------------------");\
    for (NSString *familyName in familyNames)\
    {\
        NSLog(@"%@", familyName);\
        fonts = [[UIFont fontNamesForFamilyName:familyName] sortedArrayUsingDescriptors:@[[NSSortDescriptor sortDescriptorWithKey:@"description" ascending:YES selector:@selector(localizedCaseInsensitiveCompare:)]]];\
        for (NSString *fontName in fonts)\
            NSLog(@"\t\t%@", fontName);\
        NSLog(@"\n");\
    }\
    NSLog(@"-------------------------------");\
}  while(0)
