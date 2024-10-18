// Fill out your copyright notice in the Description page of Project Settings.


#include "test_blur.h"

// Sets default values
Atest_blur::Atest_blur()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void Atest_blur::TestOpenCV()
{

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT(CV_VERSION));
	
	//cv::Mat webcam_image;
	cv::Mat img = cv::imread("D:/behram/UE5_dev/opencv_nick/UE5_opencv/test_blur_two/Data/adipurush.png", cv::IMREAD_COLOR); 

	if (img.empty())
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("img is empty"));
	}
	else
	{
		int image_width = img.rows;
		int image_height = img.cols;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("dimensions width = %d,height = %d"), image_width, image_height));
	}

}

void Atest_blur::OpenCVGausianBlur()
{

    // READ an image 
//  Mat img_grayscale = imread("adipurush.png", 0); // image file is copied to the Vstudio project under source files 
    //Mat img_grayscale = imread("D:\\behram\\C_dev\\opencv\\learn_opencv\\adipurush.png",0); // image file is in local folder
    cv::Mat img_color = imread("D:/behram/UE5_dev/opencv_nick/UE5_opencv/test_blur_two/Data/adipurush.png", cv::IMREAD_COLOR);
    auto outout_path = "D:/behram/UE5_dev/opencv_nick/UE5_opencv/test_blur_two/Data/dest/";


    // BLUR CODE
    // Apply identity filter using kernel
    cv::Mat kernel1 = (cv::Mat_<double>(3, 3) << 0, 0, 0, 0, 1, 0, 0, 0, 0);
    cv::Mat identity;
    filter2D(img_color, identity, -1, kernel1, cv::Point(-1, -1), 0, 4);
  

    // Blurred using kernel
    // Initialize matrix with all ones
    cv::Mat kernel2 = cv::Mat::ones(7, 7, CV_64F);

    // Normalize the elements
    kernel2 = kernel2 / 25;
    cv::Mat img;
    filter2D(img_color, img, -1, kernel2, cv::Point(-1, -1), 0, 4);
    /*  imshow("Original", img_color);
      imshow("Kernel blur", img);*/
    //imwrite("blur_kernel.jpg", img);
//    imwrite("D:/behram/UE5_dev/opencv_nick/UE5_opencv/test_blur_two/Data/dest/blur_kernel.jpg", img);



    // Destroys all the windows created                         
    //destroyAllWindows();


}

// Called when the game starts or when spawned
void Atest_blur::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("constructor test"));
	
	//TestOpenCV();
    OpenCVGausianBlur();
	
}

// Called every frame
void Atest_blur::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

