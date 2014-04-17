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
Miscellaneous macros, to disable / enable user interaction on application, to check system version, etc.. Have a look at file to know more

```
IS_RETINA_SCREEN()
IS_IPHONE()
IS_IPAD()
IS_IPHONE_5()

SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"7.1");
SYSTEM_VERSION_IS_IOS6_OR_GREATER();
SYSTEM_VERSION_IS_IOS7_OR_GREATER();
```

### GONUtilsMacros.h
Utils macros such as nil <=> NSNull conversion, file operations, etc...

```
// nil / NSNull convertion
nilToNSNull(value)
NSNullToNil(value)

// Unsubscribe current object from all notifications
NOTIFICATION_CENTER_REMOVE

// User interaction (when using animations for example)
ENABLE_USER_INTERACTIONS
DISABLE_USER_INTERACTIONS

// Xib
LOAD_NIB_NAMED(@"myXib");

// Files manipulation
PATH_DOCUMENTS
PATH_LIBRARY
REMOVE_ITEM_AT_PATH()
FILE_EXISTS_AT_PATH()
```

### GONViewMacros.h
Macros used for easy view frame manipulation, explicit autoresizing mask, etc...

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

##Usage
Simply call macros you want to use with appropriate parameters

##Installation
__Cocoapods__: `pod 'GONMacros'`<br>
__Manual__: Copy the __Classes__ folder in your project<br>

Import wanted headers in your project. .pch is a good place ;)
You can also import GONMacros_All.h to add all macros in your project

##Versions
1.0 : Initial release<br/>
