LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)
LOCAL_ARM_MODE := arm
LOCAL_SRC_FILES := \
	    vivi_camera.c
LOCAL_MODULE:= vivi_camera
LOCAL_MODULE_TAGS := optional
include $(BUILD_EXECUTABLE)
