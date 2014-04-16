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
Provide some macros to generate default implementation in view controllers using FRC and tableviews.
You can use only ONE  of this method at a time per view controller.
You have to declare and configure toy FRC in order to use theses macros.
Do not forget to set your view controller as delegate of your FRC.

<br/>_FRC_TABLEVIEW_DEFAULT_IMPLEMENTATION_<br/>
Will provide a default implementation for your class FRC.
Assume that your view controller has a __self.tableView__ UITableView property.
Default implementation will simply add / remove section and rows from your table view.
__tableView:willDisplayCell:forRowAtIndexPath:__ will be called is an object is refreshed, so you have to implement this method in your view controller.

<br/>_FRC_TABLEVIEW_DEFAULT_IMPLEMENTATION_FOR_TABLEVIEW(aTableView)_<br/>
Same as __FRC_TABLEVIEW_DEFAULT_IMPLEMENTATION__ but allowing you to specify another property for your tableView
```
FRC_TABLEVIEW_DEFAULT_IMPLEMENTATION_FOR_TABLEVIEW(self.myNewsTableView);
```

<br/>_FRC_TABLEVIEW_DEFAULT_IMPLEMENTATION_UPDATE_SELECTOR(updateSelector)_<br/>
Same as __FRC_TABLEVIEW_DEFAULT_IMPLEMENTATION__ but allowing you to specify a selector each time your FRC is refreshed.
The selector have to be in your view controller, and takes no parameters. It will be called in __controllerDidChangeContent:__ method, so after all changes are processed

```
FRC_TABLEVIEW_DEFAULT_IMPLEMENTATION_UPDATE_SELECTOR(@selector(frcRefreshed))
```

<br/>_FRC_TABLEVIEW_DEFAULT_IMPLEMENTATION_FOR_TABLEVIEW_UPDATE_SELECTOR_(_tableView, updateSelector)<br/>
Same as _FRC_TABLEVIEW_DEFAULT_IMPLEMENTATION_UPDATE_SELECTOR but allowing you to specify another property for your tableView.

```
FRC_TABLEVIEW_DEFAULT_IMPLEMENTATION_FOR_TABLEVIEW_UPDATE_SELECTOR(self.myNewsTableView, @selector(frcRefreshed));
```

### GONShortcutsMacros.h
### GONUtilsMacros.h
### GONViewMacros.h

##Usage
Simply call macros you want to use with appropriate parameters

##Example
```objective-c

```

##Installation
__Cocoapods__: `pod 'GONMacros'`<br>
__Manual__: Copy the __Classes__ folder in your project<br>

Import wanted headers in your project. .pch is a good place ;)
You can also import GONMacros_All.h to add all macros in your project

##Versions
1.0 : Initial release<br/>
