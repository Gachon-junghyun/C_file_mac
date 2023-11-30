import cv2
import numpy as np
import pyautogui

while True:

    screenshot = pyautogui.screenshot(region=(100, 100, 600, 600))
    image = np.array(screenshot)
    image = cv2.cvtColor(image, cv2.COLOR_RGB2BGR)







    # 이미지 표시
    cv2.imshow('Real-time Screen Capture', image)

    # ESC 키를 누르면 종료
    if cv2.waitKey(1) == 27:
        break