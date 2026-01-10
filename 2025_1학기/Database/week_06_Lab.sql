SELECT * FROM 고객;
SELECT * FROM 고객, 제품;

// 조건 검색
SELECT 제품명, 재고량, 단가
FROM 제품
WHERE 제조업체 = '한빛제과';

SELECT 주문제품, 수량, 주문일자, 주문고객
FROM 주문
WHERE 주문고객 = 'apple' AND 수량 >=15;

// LIKE를 이용한 검색
SELECT 고객이름, 나이, 등급, 적립금
FROM 고객
WHERE 고객이름 LIKE '김%';

// NULL을 이용한 검색
SELECT 고객이름
FROM 고객
WHERE 나이 IS NOT NULL;

// 정렬 검색
SELECT 고객이름, 등급, 나이
FROM 고객
ORDER BY 나이 DESC;

SELECT 주문고객, 주문제품, 수량, 주문일자
FROM 주문
WHERE 수량 >= 10
ORDER BY 주문제품 ASC, 수량 DESC;

// 집계 함수를 이용한 검색
SELECT AVG(단가)
FROM 제품;

// 그룹별 검색
SELECT 주문제품, SUM(수량) AS 총주문수량
FROM 주문
GROUP BY 주문제품
ORDER BY 주문제품;

SELECT DISTINCT 제조업체 // -> 3개 나옴
FROM 제품
GROUP BY 제조업체; // -> 3개 나옴

// GROUP BY 에 조건문을 사용할 수 있다.
SELECT 등급, COUNT(*) AS 고객수, AVG(적립금) AS 평균적립금
FROM 고객
GROUP BY 등급 HAVING AVG(적립금) >= 1000;

SELECT 주문제품, 주문고객, sum(수량)
FROM 주문
GROUP BY 주문제품, 주문고객;

// 여러 테이블에 대한 조인 검색
SELECT 제품.제품명
FROM 제품, 주문
WHERE 주문.주문고객 = 'banana' AND 제품.제품번호 = 주문.주문제품;

SELECT 고객.고객이름, 제품.제품명, 주문.수량, 주문.주문일자
FROM 고객, 주문, 제품
WHERE 고객.나이 >= 30 AND 고객.고객아이디 = 주문.주문고객 AND 주문.주문제품 = 제품.제품번호;

// INNER JOIN
SELECT *
FROM 고객 INNER JOIN 주문 ON 고객.고객아이디 = 주문.주문고객;

// 부속 질의문을 이용한 검색
SELECT 제품명, 단가
FROM 제품
WHERE 제조업체 = (SELECT 제조업체
                 FROM 제품
                 WHERE 제품명 = '달콤비스킷');