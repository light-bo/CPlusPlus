/*set the dialog display full screen*/

//retrive the screen resolution
int cx,cy;
cx = GetSystemMetrics(SM_CXSCREEN);
cy = GetSystemMetrics(SM_CYSCREEN);

//change the position and the dimensions of the windows
CRect rcTemp;
rcTemp.BottomRight() = CPoint(cx, cy);
rcTemp.TopLeft() = CPoint(0, 0);
MoveWindow(&rcTemp);


