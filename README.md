# 🎓 SMU_Uni (2023 - 2025)

### 📅 2023
| 학기 | 과목명 (Course) | 사용 언어 | 주요 학습 내용 |
|:---:|:---:|:---:|:---|
| **1학기** | **알고리즘** | Java | 정렬, 탐색, 그래프 알고리즘 구현 및 최적화 |
| **1학기** | **데이터베이스** | PL/SQL | 오라클 DB 설계 및 SQL 쿼리 실습 |

import React from 'react';
import { BookOpen, Calendar } from 'lucide-react'; // 아이콘 라이브러리 (필요시 설치 또는 svg로 대체 가능)

const CourseDashboard = () => {
  // 샘플 데이터: 실제 데이터로 교체해서 사용하세요
  const academicData = [
    {
      semester: "2025년 2학기",
      courses: ["인공지능개론", "컴퓨터네트워크", "데이터베이스설계", "웹프로그래밍"]
    },
    {
      semester: "2025년 1학기",
      courses: ["운영체제", "알고리즘", "자료구조", "객체지향프로그래밍", "선형대수학"]
    },
    {
      semester: "2024년 2학기",
      courses: ["C언어기초", "컴퓨터개론", "이산수학"]
    }
  ];

  return (
    <div className="min-h-screen bg-slate-50 py-12 px-4 sm:px-6 lg:px-8">
      <div className="max-w-5xl mx-auto">
        
        {/* 메인 헤더 */}
        <div className="mb-12 text-center">
          <h1 className="text-4xl font-extrabold text-slate-800 tracking-tight mb-2">
            My Academic Journey
          </h1>
          <p className="text-slate-500 text-lg">
            학기별 수강 과목 아카이브
          </p>
        </div>

        {/* 학기별 섹션 반복 */}
        <div className="space-y-12">
          {academicData.map((data, index) => (
            <div key={index} className="animate-fade-in-up">
              
              {/* 학기 타이틀 (스티키 헤더 느낌) */}
              <div className="flex items-center gap-2 mb-6 border-b border-slate-200 pb-2">
                <Calendar className="w-5 h-5 text-indigo-500" />
                <h2 className="text-2xl font-bold text-slate-700">
                  {data.semester}
                </h2>
              </div>

              {/* 과목 카드 그리드 */}
              <div className="grid grid-cols-1 sm:grid-cols-2 md:grid-cols-3 lg:grid-cols-4 gap-5">
                {data.courses.map((course, idx) => (
                  <div 
                    key={idx} 
                    className="group bg-white rounded-xl p-6 shadow-sm border border-slate-100 hover:shadow-md hover:border-indigo-100 transition-all duration-300 cursor-default flex flex-col justify-between h-32"
                  >
                    {/* 장식용 아이콘 */}
                    <div className="mb-2 opacity-50 group-hover:opacity-100 group-hover:text-indigo-500 transition-colors">
                      <BookOpen className="w-6 h-6" />
                    </div>
                    
                    {/* 과목명 */}
                    <h3 className="text-lg font-semibold text-slate-800 group-hover:text-indigo-600 transition-colors">
                      {course}
                    </h3>
                  </div>
                ))}
              </div>
            </div>
          ))}
        </div>

        {/* 푸터 여백 */}
        <div className="h-20"></div>
      </div>
    </div>
  );
};

export default CourseDashboard;
