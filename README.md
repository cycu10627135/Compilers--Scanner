# **ScannerTest**
## Description
在編譯器中，token 是組成程式的最小單位，需要由 Scanner 先把 input text 按照規
則轉為 Token，才能讓 Parser 進行處理。請依照題目規則，試著寫一個 Scanner 來
取得 Tokens 並印出。
  
| Terminal  | Regular Expression | 
|-------|:-----:|
| NUM | ( [1-9][0-9]* ) \| 0 |
| PLUS  | \\+ |
| MINUS | \\- |
| MUL | \\* |
| DIV | \\\\ |
| LPR | \\( |
| RPR | \\) |
  
## Input Format
輸入一條運算式，**每筆測試資料只會有一個運算式**，但其中可能會夾雜空格或換行。  
**此題的測試資料不會有錯誤的測試資料**  
**此題的測試資料會在 1000 字元內(不包含換行號)**  
  
## Output Format
請在切割後輸出其 Token 種類，例如+則輸出 PLUS。  
若為數字，需附上其數值，並以一個空白做為區隔。例如 0 則需輸出 NUM 0，以此類推。  
每個 token 輸出後請以\n 分隔。  

| Sample Input  | Sample Output | 
|-------|:-----:|
| 1+2 | NUM 1<br /> PLUS<br /> NUM 2<br /> |
| ( 1+ <br />  - 2<br />  )<br /> | LPR<br /> NUM 1<br /> PLUS<br /> MINUS<br /> NUM 2<br /> RPR<br />  |
|   (<br /> (1 + <br />  2 * 3<br />  / 4 )<br />  )<br /> | LPR<br /> LPR<br /> NUM 1<br /> PLUS<br /> NUM 2<br /> MUL<br /> NUM 3<br /> DIV<br /> NUM 4<br /> RPR<br /> RPR<br /> |
