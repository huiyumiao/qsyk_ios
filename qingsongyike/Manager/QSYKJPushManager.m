//
//  QSYKJPushManager.m
//  qingsongyike
//
//  Created by 苗慧宇 on 5/4/16.
//  Copyright © 2016 subo. All rights reserved.
//

#import "QSYKJPushManager.h"
#import "JPUSHService.h"

@implementation QSYKJPushManager

+ (QSYKJPushManager *)sharedManager {
    static QSYKJPushManager *instance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        instance = [[QSYKJPushManager alloc] init];
    });
    
    return instance;
}

- (instancetype)init {
    self = [super init];
    if (self) {
        
        if (SYSTEM_VERSION >= 8.0) {
            // 可以添加自定义categories
            [JPUSHService registerForRemoteNotificationTypes:(UIUserNotificationTypeBadge |
                                                              UIUserNotificationTypeSound |
                                                              UIUserNotificationTypeAlert)
                                                  categories:nil];
        } else {
            // categories 必须为nil
            [JPUSHService registerForRemoteNotificationTypes:(UIRemoteNotificationTypeBadge |
                                                              UIRemoteNotificationTypeSound |
                                                              UIRemoteNotificationTypeAlert)
                                                  categories:nil];
        }
        
        
        [JPUSHService setupWithOption:@{}
                               appKey:@"fc5f4abbf32e8d25f4603db6"
                              channel:@"App Store"
                     apsForProduction:NO];
        
    }
    
    return self;
}

@end
