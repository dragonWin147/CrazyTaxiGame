LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/HelloWorldScene.cpp \
                   ../../Classes/Scene/MainMenu.cpp \
                   ../../Classes/Scene/TurtleCar.cpp \
                   ../../Classes/Scene/Car.cpp \
                   ../../Classes/Scene/BlueCar.cpp \
                   ../../Classes/Scene/OrangeCar.cpp \
                   ../../Classes/Scene/BlueTruckCar.cpp \
                   ../../Classes/Scene/PinkCar.cpp \
                   ../../Classes/Scene/XTLayer.cpp \
                   ../../Classes/Scene/CollisionDetection.cpp \
                   ../../Classes/Scene/MapGame.cpp


LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

LOCAL_WHOLE_STATIC_LIBRARIES += cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
LOCAL_WHOLE_STATIC_LIBRARIES += chipmunk_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,cocos2dx)
$(call import-module,cocos2dx/platform/third_party/android/prebuilt/libcurl)
$(call import-module,CocosDenshion/android)
$(call import-module,extensions)
$(call import-module,external/Box2D)
$(call import-module,external/chipmunk)
