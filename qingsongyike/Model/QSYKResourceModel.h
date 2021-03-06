//
//  QSYKResourceModel.h
//  qingsongyike
//
//  Created by 苗慧宇 on 4/24/16.
//  Copyright © 2016 subo. All rights reserved.
//

#import <JSONModel/JSONModel.h>
#import "QSYKImageModel.h"
#import "QSYKVideoModel.h"
#import "QSYKPostModel.h"

@interface QSYKResourceModel : JSONModel
@property (nonatomic, copy  ) NSString  *sid;
@property (nonatomic, copy  ) NSString  *content;
@property (nonatomic, copy  ) NSString  *username;
@property (nonatomic, copy  ) NSString  *userAvatar;
@property (nonatomic, copy  ) NSString  *pubTime;
@property (nonatomic, strong) QSYKImageModel *img;
@property (nonatomic, strong) QSYKVideoModel *video;
@property (nonatomic, copy  ) NSString  *start; // 加载更多时使用字段
@property (nonatomic, assign) NSInteger type;   // 资源类型（0：推荐，1：文字，2：图片，3：视频）
@property (nonatomic, assign) NSInteger dig;    // 被顶数
@property (nonatomic, assign) NSInteger bury;   // 被踩数
@property (nonatomic, assign) NSInteger share;  // 分享数
@property (nonatomic, assign) NSInteger post;   // 评论数
@property (nonatomic, assign) NSInteger favorite;   // 喜爱数
@property (nonatomic, assign) BOOL      isHot;      // 是否热门

@property (nonatomic, strong) QSYKPostModel<Optional> *postList;

@end

@interface QSYKResourceList : NSObject
@property (nonatomic, strong) NSArray *list;

- (instancetype)initWithArray:(NSArray *)array;

@end
