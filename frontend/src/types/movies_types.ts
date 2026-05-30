export type CategoryMovie = | "Romance" | "Action" | "Comedy" | "Drama" | "Horror" | "SciFi" | "Documentary" | "Thriller" | "Animation";

export type Movie = {
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
export type DecisionNode = {
    id: string;
    question?: string;   
    isLeaf: boolean;
    filters?: Filters;   
}