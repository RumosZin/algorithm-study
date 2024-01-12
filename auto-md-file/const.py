# README 작성 관련 변수 정보 저장
MD_NAME = "MyWorkBook.md"
MD_HEADER = {
    "baekjoon": "Baekjoon 문제 풀이 내역",
    "programmers": "Programmers 문제 풀이 내역",
    "softeer": "Softeer 문제 풀이 내역"
}
CONCAT_MD_HEADER = """\
# My Algorithm Evolution
- 내가 푼 알고리즘 문제들을 모아서 WorkBook을 만듭니다.
- 알고리즘 문제를 풀고 commit하면, 자동으로 WorkBook이 업데이트 됩니다. 

"""
MD_TABLE = """\
| \# | Date | Problem | Solution | Difficulty | Solved |
| :----: | :------: | :---------------: | :-----: | :------: | :-------: |\
"""
MD_DIFFICULTY = {
    # Programmers
    "LV1": "⭐☆☆☆☆",
    "LV2": "⭐⭐☆☆☆",
    "LV3": "⭐⭐⭐☆☆",
    "LV4": "⭐⭐⭐⭐☆",
    "LV5": "⭐⭐⭐⭐⭐",
    # Softeer
    "1": "⭐☆☆☆☆",
    "2": "⭐⭐☆☆☆",
    "3": "⭐⭐⭐☆☆",
    "4": "⭐⭐⭐⭐☆",
    "5": "⭐⭐⭐⭐⭐",
    # Baekjoon
    "B5": "![티어](/auto-readme/src/1.svg)",
    "B4": "![티어](/auto-readme/src/2.svg)",
    "B3": "![티어](/auto-readme/src/3.svg)",
    "B2": "![티어](/auto-readme/src/4.svg)",
    "B1": "![티어](/auto-readme/src/5.svg)",
    "S5": "![티어](/auto-readme/src/6.svg)",
    "S4": "![티어](/auto-readme/src/7.svg)",
    "S3": "![티어](/auto-readme/src/8.svg)",
    "S2": "![티어](/auto-readme/src/9.svg)",
    "S1": "![티어](/auto-readme/src/10.svg)",
    "G5": "![티어](/auto-readme/src/11.svg)",
    "G4": "![티어](/auto-readme/src/12.svg)",
    "G3": "![티어](/auto-readme/src/13.svg)",
    "G2": "![티어](/auto-readme/src/14.svg)",
    "G1": "![티어](/auto-readme/src/15.svg)",
    "P5": "![티어](/auto-readme/src/16.svg)",
    "P4": "![티어](/auto-readme/src/17.svg)",
    "P3": "![티어](/auto-readme/src/18.svg)",
    "P2": "![티어](/auto-readme/src/19.svg)",
    "P1": "![티어](/auto-readme/src/20.svg)",
    "D5": "![티어](/auto-readme/src/21.svg)",
    "D4": "![티어](/auto-readme/src/22.svg)",
    "D3": "![티어](/auto-readme/src/23.svg)",
    "D2": "![티어](/auto-readme/src/24.svg)",
    "D1": "![티어](/auto-readme/src/25.svg)",
    "R5": "![티어](/auto-readme/src/26.svg)",
    "R4": "![티어](/auto-readme/src/27.svg)",
    "R3": "![티어](/auto-readme/src/28.svg)",
    "R2": "![티어](/auto-readme/src/29.svg)",
    "R1": "![티어](/auto-readme/src/30.svg)",
}
# 파일명 사용 불가로 사용할 수 없는 문자들
MD_S_CHARS = {
    "＼": "\\",
    "／": "/",
    "：": ":",
    "＊": "*",
    "？": "?",
    "＂": '"',
    "＜": "<",
    "＞": ">",
    "｜": "|"
}