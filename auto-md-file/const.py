# README 작성 관련 변수 정보 저장
MD_NAME = "README.md"
MD_HEADER = {
    "baekjoon": "Baekjoon 문제 풀이 내역",
    "programmers": "Programmers 문제 풀이 내역",
    "softeer": "Softeer 문제 풀이 내역"
}
CONCAT_MD_HEADER = """\
# Problem Solving
- 알고리즘 풀이 내역을 정리합니다.
- 풀이 내역은 업로드 시, [자동으로 업데이트](https://github.com/woodywarhol9/algorithm-practice)됩니다.
- 스스로 풀이에 성공한 경우 ✔️를, 다른 사람의 풀이를 참고해서 풀었으면 ❌로 표시했습니다.
### 사이트 별 문제 확인
"""
MD_TABLE = """\
| \# | Date | Problem | Solution | Difficulty | Solved |
| :----: | :------: | :---------------: | :-----: | :------: | :-------: |\
"""
MD_DIFFICULTY = {
    # Baekjoon
    "B5": "B5",
    "B4": "B4",
    "B3": "B3",
    "B2": "B2",
    "B1": "B1",
    "S5": "S5",
    "S4": "S4",
    "S3": "S3",
    "S2": "S2",
    "S1": "S1",
    "G5": "G5",
    "G4": "G4",
    "G3": "G3",
    "G2": "G2",
    "G1": "G1",
    "P5": "P5",
    "P4": "P4",
    "P3": "P3",
    "P2": "P2",
    "P1": "P1",
    "D5": "D5",
    "D4": "D4",
    "D3": "D3",
    "D2": "D2",
    "D1": "D1",
    "R5": "R5",
    "R4": "R4",
    "R3": "R3",
    "R2": "R2",
    "R1": "R1",
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