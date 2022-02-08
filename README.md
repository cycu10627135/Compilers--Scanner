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
