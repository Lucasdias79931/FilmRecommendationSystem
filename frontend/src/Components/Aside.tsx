import type { Movie } from "../types/movies_types";

interface AsideProps {
  movies: Movie[];
  loading: boolean;
  title?:string
}

const Aside = ({ movies, loading, title = "Top Movies" }: AsideProps) => {
    if(loading){
        return <aside>
            <h1>Carregando</h1>
        </aside>
    }

    return (
        
        <aside>
            
            <h1>{title}</h1>
            <ul>
               {movies.slice(0,5).map((movie, index)=>(
                <li key={movie.id?? index}>
                    {movie.name} ⭐ {movie.rate}
                </li>
               ))}
            </ul>
        </aside>
    )
    
};





export default Aside;