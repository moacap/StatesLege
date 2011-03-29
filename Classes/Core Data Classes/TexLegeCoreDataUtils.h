//
//  TexLegeCoreDataUtils.h
//  TexLege
//
//  Created by Gregory Combs on 8/31/10.
//  Copyright 2010 Gregory S. Combs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>

#if DEBUG
#define RESTKIT_BASE_URL					@"http://www.texlege.com/jsonDataTest"
#else
#define RESTKIT_BASE_URL					@"http://www.texlege.com/rest"
#endif

//@class TexLegeDataMaintenance;

@class LegislatorObj, CommitteeObj, DistrictMapObj;
@interface TexLegeCoreDataUtils : NSObject {

}
+ (id) fetchCalculation:(NSString *)calc ofProperty:(NSString *)prop withType:(NSAttributeType)retType onEntity:(NSString *)entityName;

+ (id)dataObjectWithPredicate:(NSPredicate *)predicate entityName:(NSString*)entityName lightProperties:(BOOL)light;
+ (id)dataObjectWithPredicate:(NSPredicate *)predicate entityName:(NSString*)entityName;
+ (id)dataObjectWithPredicate:(NSPredicate *)predicate entityName:(NSString*)entityName;
+ (LegislatorObj*)legislatorForDistrict:(NSNumber*)district andChamber:(NSNumber*)chamber;
+ (DistrictMapObj*)districtMapForDistrict:(NSNumber*)district andChamber:(NSNumber*)chamber;
+ (DistrictMapObj*)districtMapForDistrict:(NSNumber*)district andChamber:(NSNumber*)chamber lightProperties:(BOOL)light;

+ (NSArray *) allLegislatorsSortedByPartisanshipFromChamber:(NSInteger)chamber andPartyID:(NSInteger)party;
+ (NSArray *) allDistrictMapsLight;
+ (NSArray *) allDistrictMapIDsWithBoundingBoxesContaining:(CLLocationCoordinate2D)coordinate;
+ (NSArray*) allPrimaryKeyIDsInEntityNamed:(NSString*)entityName;

+ (void) deleteObjectInEntityNamed:(NSString *)entityName withPrimaryKeyValue:(id)keyValue;
+ (void) deleteAllObjectsInEntityNamed:(NSString*)entityName;

//+ (void)loadDataFromRest:(NSString *)entityName delegate:(id)delegate;
+ (void)initRestKitObjects:(id)sender;
+ (void)resetSavedDatabase:(id)sender;
+ (NSArray *)registeredDataModels;
@end

/*
typedef enum {
    TexLegeDataMaintenanceFailOptionLog,
    TexLegeDataMaintenanceFailShowAlert,
    
	TexLegeDataMaintenanceFailOptionCount
} TexLegeDataMaintenanceFailOption;

@protocol TexLegeDataMaintenanceDelegate
- (void)dataMaintenanceDidFinishSuccessfully:(TexLegeDataMaintenance *)op;
- (void)dataMaintenanceDidFail:(TexLegeDataMaintenance *)op 
							 errorMessage:(NSString *)errorMessage 
								   option:(TexLegeDataMaintenanceFailOption)failOption;
@end

@interface TexLegeDataMaintenance : NSOperation 
{
    __weak  NSObject <TexLegeDataMaintenanceDelegate> *delegate;
}
@property (assign) NSObject <TexLegeDataMaintenanceDelegate> *delegate;

- (id) initWithDelegate:(id<TexLegeDataMaintenanceDelegate>)newDelegate;

@end
 */
