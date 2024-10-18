// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
//#with_opencv = 1;

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PreOpenCVHeaders.h"
//#include "OpenCVHelper.h" // DOS NOT WORK  error C4430: missing type specifier - int assumed. Note: C++ does not support default-int
#include "opencv2/unreal.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include "opencv2/ml.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "PostOpenCVHeaders.h"

#include "test_blur.generated.h"

UCLASS()
class TEST_BLUR_TWO_API Atest_blur : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Atest_blur();

	// OPENCV FEILDS
	cv::Mat frame;
	cv::VideoCapture stream;
	cv::Size size;

	void TestOpenCV();
	void OpenCVGausianBlur();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
