export type CategoryMovie = | "Romance" | "Action" | "Comedy" | "Drama" | "Horror" | "SciFi" | "Documentary" | "Thriller" | "Animation";
export type IdMovie = string | number;

export interface Movie{
    id?: IdMovie;
    name: string;
    category: CategoryMovie; 
    origin: string;
    style: string;
    pace: string;
    year: number;
    rate: number;
};




export interface Filters {
    category: CategoryMovie;
    origin: "National" | "Foreign"; 
    style: "Realistic" | "Fantasy";
    pace: "Fast" | "Slow";
}
export interface DecisionNode  {
    id: string;
    question?: string;   
    isLeaf: boolean;
    filters?: Filters;   
}

