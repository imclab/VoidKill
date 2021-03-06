#include "vk.h"

//--------------------------------------------------------------
void vk::setup(){
    // I assume in here I will get ready to launch, weapons checks etc.
    // need to check with base to see if ready to go
    receiveInstructions();
    
    if (authorized_to_launch) {
        preflightCheck();
        // This seems a good thing, I'll make sure I won't explode when I take off
        checkWeapons();
        // need to make sure there is a runway open, etc.
        waitForClearance();
        takeoff();
    }
}

void vk::takeoff(){
    // now I'm in the air at some millitary base, better get out of their airspace first thing
    exitAirspace();
    receiveInstructions();
    
    // command has authorized this mission and I can travel into enemy air space
    // now I'm totally on my own
    if (approved_for_mission) {
        setDestination();
        flyToDestination();
    }
}



//--------------------------------------------------------------
void vk::aquireTarget(){
    // this mission is unspecific, I am just supposed to go into the enemy space and patrol
    // if I see something fishy I should investigate it
    // if this method has been called my sensors have detected a person
    // now check the database and see if I can identify this person
    target = identifyTarget();
    
    // if this is a known person on the kill list, maybe I should kill him or her
    if (isTargetOnKillList(target)) {
        // I need to check internally with moral and legal frameworks to see if I can kill this target
        // this internal checking happens without external communication, I decide on my own to kill.
        if (authorizeMyselfToUseDeadlyForce()) {
            kill();
            escape();
        }
    // the person is not on the kill list, but if they are dangerous I should kill them
    } else {
        if (isTargetHostile(target)){
            if (evaluateThreat() > threat_threshold && authorizeMyselfToUseDeadlyForce()) {
                kill();
                escape();
            }
        }
    }
}



//--------------------------------------------------------------
void vk::kill(){
    // this is where I kill someone
}