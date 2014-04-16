//
//  GONARCMacros.h
//
//  Created by Nicolas Goutaland on 04/03/14.
//  Copyright 2014 Nicolas Goutaland. All rights reserved.
//

#define SuppressPerformSelectorLeakWarning(Stuff) \
do { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
Stuff; \
_Pragma("clang diagnostic pop") \
} while (0)
