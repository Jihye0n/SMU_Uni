SELECT *
FROM 주문
WHERE 주문고객 = 'banana';

// 부속 질의문 : IN
SELECT 제품명, 제조업체
FROM 제품
WHERE 제품번호 IN (SELECT 주문제품
                  FROM 주문
                  WHERE 주문고객 = 'banana');
           
                 
// 부속 질의문 : NOT IN 
SELECT 제품명, 제조업체
FROM 제품
WHERE 제품번호 NOT IN (SELECT 주문제품
                      FROM 주문
                      WHERE 주문고객 = 'banana');
                      
SELECT 제품명, 단가, 제조업체
FROM 제품
WHERE 단가 > ALL (SELECT 단가
                  FROM 제품
                  WHERE 제조업체 = '대한식품');
              
                  
// 데이터 삽입 : INSERT 문
// 데이터 직접 삽입
INSERT
INTO 고객(고객아이디, 고객이름, 나이, 등급, 직업, 적립금)
VALUES ('strawberry', '최유경', '30', 'vip', '공무원', 100);

SELECT * FROM 고객;


// 데이터 수정 : UPDATE 문
UPDATE 제품
SET 제품명 = '통큰파이'
WHERE 제품번호 = 'p03';

SELECT * FROM 제품;


// 데이터 삭제 : DELETE 문
DELETE
FROM 주문
WHERE 주문일자 = '2022-05-22';

SELECT * FROM 주문;

// 뷰 생성 : CREATE VIEW 문
CREATE VIEW 우수고객(고객아이디, 고객이름, 나이, 등급)
AS SELECT 고객아이디, 고객이름, 나이, 등급
FROM 고객
WHERE 등급 = 'vip'
WITH CHECK OPTION;

SELECT * FROM 우수고객;
                      