//
//  BTKey.h
//  bitheri
//
//  Copyright 2014 http://Bither.net
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

#import <Foundation/Foundation.h>

#define SALT_LENGTH              8
#define IS_COMPRESSED_FLAG       1
#define IS_FROMXRANDOM_FLAG      2

@interface BTKey : NSObject

@property (nonatomic, copy) NSString *privateKey;
@property (nonatomic, copy) NSData *publicKey;
@property (nonatomic, readonly) NSString *address;
@property (nonatomic, readonly) NSData *hash160;
@property BOOL compressed;
@property BOOL isFromXRandom;

+ (instancetype)keyWithPrivateKey:(NSString *)privateKey;
+ (instancetype)keyWithSecret:(NSData *)secret compressed:(BOOL)compressed;
+ (instancetype)keyWithPublicKey:(NSData *)publicKey;

- (instancetype)initWithPrivateKey:(NSString *)privateKey;
- (instancetype)initWithSecret:(NSData *)secret compressed:(BOOL)compressed;
- (instancetype)initWithPublicKey:(NSData *)publicKey;

- (NSData *)sign:(NSData *)d;
- (BOOL)verify:(NSData *)d signature:(NSData *)sig;

@end
