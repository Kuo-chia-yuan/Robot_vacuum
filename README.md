<p>介紹 : 這是資料結構課程，製作的掃地機器人，用C++寫，只要輸入地圖大小、障礙物位置，便能輸出從充電站出發 -> 所有區域皆掃過 -> 回到充電站的路徑，算是簡易的人工智慧。<p>
<p>技巧 : 先用queue & bfs算出地圖所有位置與充電站的距離，再從最遠的點至充電站，利用兩次dfs遞迴，不斷紀錄並更新所掃過的路徑，直到所有路徑皆被掃過。<p>
<p>附上Robot_vacuum.cpp及詳細report。<p>
