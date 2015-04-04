#GONMacros

Set of useful macros and consts I've been using in project for years.

##Description
Add some macros to your project.

ARC Only

### __GONMacros_All.h__
Contains all macro headers

### GONARCMacros.h
ARC related macros<br/>
<br/>
_SuppressPerformSelectorLeakWarning(Stuff)_
<br/>
Disable clangs warning message on perform selector when using arc
```
SuppressPerformSelectorLeakWarning([self performSelector:@selector(mySelector)]);
```

### GONFRCMacros.h
Provide some macros to generate default implementation in view controllers using `NSFetchedResultsController` and `UITableView` / `UICollectionView`.
You can use only ONE of these methods at a time per `UIViewController`.
You have to declare and configure your `NSFetchedResultsController` in order to use theses macros.
Do not forget to set your `UIViewVontroller` as delegate of your `NSFetchedResultsController`.

<br/>_FRC_TABLEVIEW_DEFAULT_IMPLEMENTATION_<br/>
Will provide a default implementation for your class' `NSFetchedResultsController`.
Assume that your view controller has a __self.tableView__ `UITableView` property.
Default implementation will simply add / remove section and rows from your `UITableView`.
__tableView:willDisplayCell:forRowAtIndexPath:__ will be called is an object is refreshed, so you have to implement this method in your `UIViewController`.
```
FRC_TABLEVIEW_DEFAULT_IMPLEMENTATION
```

<br/>_FRC_TABLEVIEW_DEFAULT_IMPLEMENTATION_FOR_TABLEVIEW(aTableView)_<br/>
Same as __FRC_TABLEVIEW_DEFAULT_IMPLEMENTATION__ but allowing you to specify another property for your `UITableView`
```
FRC_TABLEVIEW_DEFAULT_IMPLEMENTATION_FOR_TABLEVIEW(self.myNewsTableView);
```

<br/>_FRC_TABLEVIEW_DEFAULT_IMPLEMENTATION_UPDATE_SELECTOR(updateSelector)_<br/>
Same as __FRC_TABLEVIEW_DEFAULT_IMPLEMENTATION__ but allowing you to specify a selector each time your `NSFetchedResultsController` is refreshed.
The selector have to be in your view controller, and takes no parameters. It will be called in __controllerDidChangeContent:__ method, so after all changes are processed

```
FRC_TABLEVIEW_DEFAULT_IMPLEMENTATION_UPDATE_SELECTOR(@selector(frcRefreshed))
```

<br/>_FRC_TABLEVIEW_DEFAULT_IMPLEMENTATION_FOR_TABLEVIEW_UPDATE_SELECTOR_(_tableView, updateSelector)<br/>
Same as __FRC_TABLEVIEW_DEFAULT_IMPLEMENTATION_UPDATE_SELECTOR__ but allowing you to specify another property for your `UITableView`.

```
FRC_TABLEVIEW_DEFAULT_IMPLEMENTATION_FOR_TABLEVIEW_UPDATE_SELECTOR(self.myNewsTableView, @selector(frcRefreshed));
```

<br/>_FRC_COLLECTIONVIEW_DEFAULT_IMPLEMENTATION_<br/>
Will provide a default implementation for your class' `NSFetchedResultsController`.
Assume that your `UIViewController` has a __self.collectionView__ `UICollectionView` property.
Default implementation will simply add / remove section and rows from your `UICollectionView`.
__tableView:willDisplayCell:forRowAtIndexPath:__ will be called is an object is refreshed, so you have to implement this method in your `UIViewController`.

```
FRC_COLLECTIONVIEW_DEFAULT_IMPLEMENTATION
```

<br/>_FRC_COLLECTIONVIEW_DEFAULT_IMPLEMENTATION_FOR_COLLECTIONVIEW(aCollectionView)_<br/> 
Same as __FRC_COLLECTIONVIEW_DEFAULT_IMPLEMENTATION__ but allowing you to specify another property for your `UICollectionView`
```
FRC_COLLECTIONVIEW_DEFAULT_IMPLEMENTATION_FOR_COLLECTIONVIEW(self.myNewsCollectionView);
```

<br/>_FRC_COLLECTIONVIEW_DEFAULT_IMPLEMENTATION_UPDATE_SELECTOR(updateSelector)_<br/> 
Same as __FRC_COLLECTIONVIEW_DEFAULT_IMPLEMENTATION__ but allowing you to specify a selector each time your `NSFetchedResultsController` is refreshed.
The selector have to be in your view controller, and takes no parameters. It will be called in __controllerDidChangeContent:__ method, so after all changes are processed

```
FRC_COLLECTIONVIEW_DEFAULT_IMPLEMENTATION_UPDATE_SELECTOR(@selector(frcRefreshed))
```

<br/>_FRC_COLLECTIONVIEW_DEFAULT_IMPLEMENTATION_FOR_COLLECTIONVIEW_UPDATE_SELECTOR(aCollectionView, updateSelector)_<br/>
Same as __FRC_COLLECTIONVIEW_DEFAULT_IMPLEMENTATION_UPDATE_SELECTOR__ but allowing you to specify another property for your `UICollectionView`.

```
_FRC_COLLECTIONVIEW_DEFAULT_IMPLEMENTATION_FOR_COLLECTIONVIEW_UPDATE_SELECTOR(self.myNewsCollectionView, @selector(frcRefreshed));
```


### GONShortcutsMacros.h
Shortcut macros to access several iOS framework sharedInstance
```
// NSLocalizedString
LOCALIZED_STRING(string)               

// Lang shortcuts
LANG                                       
LANG_DISPLAY                               

// Shared instance shortcuts
NOTIFICATION_CENTER                        
FILE_MANAGER                               
MAIN_BUNDLE                                
MAIN_THREAD                                
MAIN_SCREEN                                
USER_DEFAULTS                              
APPLICATION                                
CURRENT_DEVICE                             
MAIN_RUN_LOOP                              
GENERAL_PASTEBOARD                         

// Network
NETWORK_ACTIVITY              // Check if network activity indicator is displayed or not                      

// Color consts
CLEAR_COLOR                   // Shortcut for [UIColor clearColor]

// Application informations
APPLICATION_NAME                           
APPLICATION_VERSION                        
APPLICATION_BUILD_VERSION                  
APPLICATION_BUNDLE_ID                      
```

### GONUtilsMacros.h
Utils macros such as nil <=> NSNull conversion, file operations, to disable / enable user interaction on application, etc...
Check file for more information
```
// nil / NSNull conversion
nilToNSNull(value)
NSNullToNil(value)

// Unsubscribe current object from all notifications
NOTIFICATION_CENTER_REMOVE

// User interaction (when using animations for example)
ENABLE_USER_INTERACTIONS
DISABLE_USER_INTERACTIONS

// Xib
LOAD_NIB_NAMED(@"myXib")      // Load a xib, using self as owner

// Dump all available font on device. Useful to check if custom font are right imported and check there names
DUMP_FONT_LIST()

// Files manipulation
PATH_DOCUMENTS
PATH_LIBRARY
REMOVE_ITEM_AT_PATH()
FILE_EXISTS_AT_PATH()
```

### GONViewMacros.h
Macros used for easy view frame/bounds manipulation, explicit autoresizing mask, etc...

```
// Frame update
UPDATE_FRAME_X(10);                     // When called from a UIView subclass
UPDATE_VIEW_FRAME_X(_tableView, 15.0);  // To specify view to update

UPDATE_VIEW_FRAME_HEIGHT(_tableView, 150.0);

// Autoresizing masks
self.view.autoresizingMask = UIViewAutoresizingTopAlign;        // View will stay top aligned to its parent view, without resizing
self.view.autoresizingMask = UIViewAutoresizingBottomAlign;     // View will stay bottom aligned to its parent view, without resizing
self.view.autoresizingMask = UIViewAutoresizingCentered;        // View will stay centered in parent view, without resizing
self.view.autoresizingMask = UIViewAutoresizingFill;            // View will stay centered in parent view, with resizing in all directions
```

### GONSharedInstanceMacro.h
Macros used to add a shared instance to any class

```
SHARED_INSTANCE_PROTO;              // Macro to put in your header file, if you want your sharedInstance method to be public

SHARED_INSTANCE_IMPL;               // Macro to put in your implementation file, if you want your sharedInstance method to be public
SHARED_INSTANCE(myClass)            // Macro to put in your implementation file, at top to implement sharedInstance
SHARED_INSTANCE_TERMINATE(myClass, selector)  // Same as SHARED_INSTANCE, but allowing to to set a selector automatically called when application will terminate
```

### GONCoreGraphics.h
Math related macros

```
DEGREES_TO_RADIANS(degrees)
RADIANS_TO_DEGREES(radians)
```

### GONMaths.h
CoreGraphics related macros

```
CGizeMultiply(size, mult)       // Will return a size with members multiplied by mult
```

### GONDevices.h
Macros used to determine current device, system version, etc...

```
// Device
IS_IPHONE()
IS_IPAD()
IS_IPHONE_5()
IS_IPHONE_6()
IS_IPHONE_6Plus()

// Device information
DEVICE_MODEL                                
DEVICE_LOCALIZED_MODEL                      
DEVICE_PLATFORM                             
DEVICE_SYSTEM_NAME                          
DEVICE_SYSTEM_VERSION                       

// System version
SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"7.1");
SYSTEM_VERSION_IS_IOS6_OR_GREATER();
SYSTEM_VERSION_IS_IOS7_OR_GREATER();
SYSTEM_VERSION_IS_IOS8_OR_GREATER();
```

### GONLogMacros.h
Log macros. Used to pretty print objects
You can trim them on compilation by setting **__GON_TRIM_LOG_MACROS__** flag
By default, log use __NSLog__. You can set another logger by overriding GON_LOGGER macro.

```
GONLog(msg, ...)
LOG_VIEW(view)
FRAME_TO_STRING(frame)
RECT_TO_STRING(rect)
POINT_TO_STRING(point)
SIZE_TO_STRING(size)
OBJ_TO_STRING(obj)
LOG_FRAME(frame)
LOG_RECT(rect)
LOG_POINT(point)
LOG_SIZE(size)
LOG_OBJ(obj)
DATA_TO_STR(data, dataEnc)
DATA_TO_UTF8_STRING(data)
COORDINATE_REGION_TO_STRING(region)
COORDINATE_SPAN_TO_STRING(span)
MAP_POINT_TO_STRING(mapPoint)
MAP_SIZE_TO_STRING(mapSize)
LOCATION_COORDINATE_2D_TO_STRING(coordinate)
MAP_RECT_TO_STRING(mapRect)
LOG_COORDINATE_REGION(region)
LOG_COORDINATE_SPAN(span)
LOG_MAP_POINT(mapPoint)
LOG_MAP_SIZE(mapSize)
LOG_LOCATION_COORDINATE_2D(coordinate)
LOG_MAP_RECT(mapRect)
```

##Usage
Simply call macros you want to use with appropriate parameters

##Installation
__Cocoapods__: `pod 'GONMacros'`<br>
__Manual__: Copy the __Classes__ folder in your project<br>

Import wanted headers in your project. .pch is a good place ;)
You can also import GONMacros_All.h to add all macros in your project

##Versions
1.0   : Initial release<br/>
1.0.1 : Formating, added some parenthesis to macros<br/>
1.0.2 : Refactoring<br/>
1.0.3 : Fixed bug on FRC macros<br/>
1.0.4 : Refactoring<br/>
1.1   : Added new macros<br/>
1.1.1 : Refactoring, new macros<br/>

